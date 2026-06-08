package rateLimiter;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class RateLimiterService {
    private final Map<Identifier, RaterLimiter> clientLimits;
    private final RateLimiterFactory factory;
    private final RuleEngine ruleEngine;

    public RateLimiterService(RateLimiterFactory factory, RuleEngine ruleEngine) {
        this.factory = factory;
        this.ruleEngine = ruleEngine;
        clientLimits = new ConcurrentHashMap<>();
    }

    public boolean isAllowed(Identifier clientId) {
        RaterLimiter limiter = clientLimits.computeIfAbsent(clientId, key -> factory.create(ruleEngine.getRule(key)));

        return limiter.allowRequest();
    }
}
