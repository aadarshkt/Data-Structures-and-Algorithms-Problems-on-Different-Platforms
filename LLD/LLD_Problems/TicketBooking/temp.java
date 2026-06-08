package TicketBooking;

import java.util.concurrent.*;

public class temp {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(2);

        System.out.println("Scheduling task");
        ScheduledFuture<String> future = scheduler.schedule(() -> {
            return "Task finished";
        }, 3, TimeUnit.SECONDS);

        System.out.println("Remaining seconds" + future.getDelay(TimeUnit.SECONDS) + "s");

        System.out.println("The result is " + future.get());

        scheduler.shutdown();
    }
}
