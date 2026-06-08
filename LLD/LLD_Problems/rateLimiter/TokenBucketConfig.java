package rateLimiter;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.RequiredArgsConstructor;

@Data
@RequiredArgsConstructor
@EqualsAndHashCode(callSuper = false)
public class TokenBucketConfig extends LimitConfig {
    private final int maxCapacity;
    private final int refillRatePerSecond;
}
