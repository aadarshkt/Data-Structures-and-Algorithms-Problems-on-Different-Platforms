package rateLimiter;

import java.time.LocalDateTime;

public record RateLimitState(int remainingRequests, LocalDateTime lastWindowTimestamp) {
    }
