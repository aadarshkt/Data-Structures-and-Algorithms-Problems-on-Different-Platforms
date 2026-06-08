package rateLimiter;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

//Take request and identifies which rule to apply.
public class RuleEngine {
    //keep user-id to rule mapping in ruleEngine
    private final Map<Identifier, Rule> rules = new ConcurrentHashMap<>();

    public void addRule(Identifier identifier, Rule rule) {
        rules.computeIfAbsent(identifier, k -> rule);
    }

    public Rule getRule(Identifier identifier) {
        return rules.get(identifier);
    }
}
