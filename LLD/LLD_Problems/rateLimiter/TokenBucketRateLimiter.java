package rateLimiter;

public class TokenBucketRateLimiter implements RaterLimiter {

    private final TokenBucketConfig tokenBucketConfig;

    public TokenBucketRateLimiter(TokenBucketConfig tokenBucketConfig) {
        this.tokenBucketConfig = tokenBucketConfig;
    }

    void refill() {
        Long now = System.currentTimeMillis();

        int tokenAvailable = Math.toIntExact((now - tokenBucketConfig.getLastRefillTimestamp()) * tokenBucketConfig.getRefillRatePerSecond() / 1000);
        tokenBucketConfig.setCurrentTokens(Math.min(tokenAvailable + tokenBucketConfig.getCurrentTokens(), tokenBucketConfig.getMaxCapacity()));

        this.tokenBucketConfig.setLastRefillTimestamp(now);
    }

    @Override
    public synchronized boolean allowRequest() {
        refill();

        if(tokenBucketConfig.getCurrentTokens() > 0) {
            tokenBucketConfig.setCurrentTokens(tokenBucketConfig.getCurrentTokens()-1);
            return true;
        }
        return false;
    }
}
