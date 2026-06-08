package rateLimiter;

import java.util.LinkedList;
import java.util.Queue;

public class SlidingWindowRateLimiter implements RaterLimiter {

    private final SlidingWindowConfig slidingWindowConfig;
    private final Queue<Long> requestTimeStamps;

    public SlidingWindowRateLimiter(SlidingWindowConfig slidingWindowConfig) {
        this.slidingWindowConfig = slidingWindowConfig;
        this.requestTimeStamps = new LinkedList<>();
    }

    @Override
    public synchronized boolean allowRequest () {
        Long now = System.currentTimeMillis();

        while(!requestTimeStamps.isEmpty() && now - requestTimeStamps.peek() > slidingWindowConfig.getWindowSizeInMillis()) {
            requestTimeStamps.poll();
        }

        if(requestTimeStamps.size() < slidingWindowConfig.getMaxRequests()) {
            requestTimeStamps.add(now);
            return true;
        }

        return false;
    }
}
