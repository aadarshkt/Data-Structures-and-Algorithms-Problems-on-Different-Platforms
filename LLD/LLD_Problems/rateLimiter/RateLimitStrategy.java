package rateLimiter;

public interface RateLimitStrategy {
    RateLimitState isAllowed(Identifier identifier, RateLimitStore rateLimitStore);
}
