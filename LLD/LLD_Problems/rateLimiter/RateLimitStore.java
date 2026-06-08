package rateLimiter;

import java.time.Duration;
import java.time.LocalDateTime;
import java.util.concurrent.ConcurrentHashMap;

public class RateLimitStore {
    //map to store current remaining requests and lastWindowTimestamp
    ConcurrentHashMap<Identifier, RateLimitState> rateLimits = new ConcurrentHashMap<>();

    //predefined window length after which counter resets.
    Duration resetDuration = Duration.ofSeconds(60);

    //methods to get value for a single identifier
    public RateLimitState getRateCurrentRateLimitState(Identifier identifier) {
        return rateLimits.get(identifier);
    }

    //method to put if current Identifier is not available. and update if available.
    public RateLimitState updateRateLimitState(Identifier identifier) {

        return rateLimits.compute(identifier, (key, value) -> {
            if(value == null) {
                return new RateLimitState(10, LocalDateTime.now());
            }

            //check current window length.
            Duration elapsedTime = Duration.between(LocalDateTime.now(), value.lastWindowTimestamp());

            if(elapsedTime.compareTo(resetDuration) > 0) {
                //reset counter and update lastWindowTimestamp to now.
                return new RateLimitState(10, LocalDateTime.now());
            }

            return new RateLimitState(value.remainingRequests()-1, value.lastWindowTimestamp());
        });
    }
}
