package rateLimiter;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.RequiredArgsConstructor;

@Data
@RequiredArgsConstructor
@EqualsAndHashCode(callSuper = false)
public class TokenBucketConfig extends LimitConfig {
    private final int maxCapacity;
    private Long lastRefillTimestamp;
    private final int refillRatePerSecond;
    private int currentTokens;
}
