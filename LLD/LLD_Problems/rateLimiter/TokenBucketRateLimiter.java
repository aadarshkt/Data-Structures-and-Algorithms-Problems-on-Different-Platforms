package rateLimiter;

public class TokenBucketRateLimiter implements RaterLimiter {

    private final TokenBucketConfig tokenBucketConfig;
    private int currentTokens;
    private Long lastRefillTimestamp;


    public TokenBucketRateLimiter(TokenBucketConfig tokenBucketConfig) {
        this.tokenBucketConfig = tokenBucketConfig;
    }

    void refill() {
        Long now = System.currentTimeMillis();

        int tokenAvailable = Math.toIntExact((now - lastRefillTimestamp) * tokenBucketConfig.getRefillRatePerSecond() / 1000);
        currentTokens = Math.min(tokenAvailable + currentTokens, tokenBucketConfig.getMaxCapacity());

        if(tokenAvailable > 0) lastRefillTimestamp = now;
    }

    @Override
    public synchronized boolean allowRequest() {
        refill();

        if(currentTokens > 0) {
            currentTokens--;
            return true;
        }
        return false;
    }
}
