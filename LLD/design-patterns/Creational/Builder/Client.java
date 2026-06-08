package Creational.Builder;

public class Client {
    public static void main(String[] args) {

        Computer personalPC = new Computer(
                new Computer.Builder("Windows11", "x86")
                        .addBattery(1000)
                        .addRAM(16)
                        .addROM(64));

        Computer officePC = new Computer(
                new Computer.Builder("Macos", "arm")
                        .addROM(64)
        );

        //second way to build an object.
        Computer secondPC = new Computer.Builder("MacOS", "arm")
                .addRAM(128)
                .addBattery(10000)
                .addROM(1)
                .build();

    System.out.println(personalPC.toString());
    System.out.println(officePC.toString());
    System.out.println(secondPC.toString());
  }
}
