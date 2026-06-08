package rateLimiter;

import lombok.Data;

import java.time.LocalDateTime;

@Data
public class Request {
    Identifier requestId;
    LocalDateTime timeStamp;
    Identifier identifierId;
}
