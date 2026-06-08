package rateLimiter;

import java.time.LocalDateTime;

public class Request {
    String requestId;
    LocalDateTime timeStamp;
    Identifier userId;
}
