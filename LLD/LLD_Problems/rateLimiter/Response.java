package rateLimiter;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class Response {
    int requestRemaining;
    String statusCode;
    String header;
}
