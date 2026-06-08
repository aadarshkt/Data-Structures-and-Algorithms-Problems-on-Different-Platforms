package rateLimiter;

public interface RateLimiterFactory {
    RaterLimiter create(Rule rule);
}
