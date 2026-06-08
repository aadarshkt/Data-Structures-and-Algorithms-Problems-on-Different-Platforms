package Behavioural.Strategy.Standard;

import java.util.Comparator;

public class Client {
    public static void main(String[] args){
        DaemonSlayer daemonSlayer = new DaemonSlayer();

        daemonSlayer.setStrategy(new GunStrategy());
        daemonSlayer.goToBattle();

        daemonSlayer.setStrategy(new KnifeStrategy());
        daemonSlayer.goToBattle();
    }
}
