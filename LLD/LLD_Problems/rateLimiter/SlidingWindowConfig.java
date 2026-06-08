package rateLimiter;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.RequiredArgsConstructor;

@Data
@RequiredArgsConstructor
@EqualsAndHashCode(callSuper=false)
public class SlidingWindowConfig extends LimitConfig {
    private final int maxRequests;
    private final long windowSizeInMillis;
}
