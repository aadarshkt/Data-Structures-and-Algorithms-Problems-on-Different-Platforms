package rateLimiter;

public class RateLimiter {
    //Current rateLimit strategy.
    RateLimitStrategy rateLimitStrategy;

    //reference to in memory rateLimit store.
    RateLimitStore rateLimitStore;

    //method to be called when request is made.
    Response getResponse(Request req) {
        //strategy will return whether this is request is possible or not.
        RateLimitState rateLimitState = rateLimitStrategy.isAllowed(req.userId, rateLimitStore);

        return new Response(rateLimitState.remainingRequests(), "409", "X-limit-request");
    }
}
