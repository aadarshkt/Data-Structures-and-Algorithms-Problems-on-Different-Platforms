package rateLimiter;

public class FixedWindowStrategy implements RateLimitStrategy{
    @Override
    public RateLimitState isAllowed(Identifier identifier, RateLimitStore rateLimitStore) {
        return rateLimitStore.updateRateLimitState(identifier);
    }
}
