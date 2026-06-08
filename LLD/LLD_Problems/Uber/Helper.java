package Uber;

public class Helper {
    static double calcDistance(Location start, Location end) {
        return Math.pow((end.latitude - start.latitude), 2) + Math.pow((end.longitude - start.longitude), 2);
    }
}
