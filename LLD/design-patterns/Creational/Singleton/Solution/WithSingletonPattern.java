package Creational.Singleton.Solution;

public class WithSingletonPattern {
    public static void main(String[] args) {
        //Step 4: Now use the single instance from getInstance method.
        AppSettings appSettings = AppSettings.getInstance();
        AppSettings appSettings1 = AppSettings.getInstance();

        //Same instance
        System.out.println(appSettings1 == appSettings);
    }
}
