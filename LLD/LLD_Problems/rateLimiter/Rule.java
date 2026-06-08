package rateLimiter;

import lombok.AllArgsConstructor;
import lombok.Data;

@AllArgsConstructor
@Data
public class Rule {
    StrategyType strategyType;
    LimitConfig limitConfig;
}
