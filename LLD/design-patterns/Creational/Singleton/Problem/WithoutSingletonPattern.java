package Creational.Singleton.Problem;

public class WithoutSingletonPattern {
    public static void main(String[] args) {
        AppSettings appSettings = new AppSettings();
        AppSettings appSettingsCopy = new AppSettings();

        //More memory
        System.out.println(appSettings == appSettingsCopy);

        //Inconsistency
        appSettingsCopy.setApiKey("12345");
        System.out.println(appSettings.getApiKey());
        System.out.println(appSettingsCopy.getApiKey());

        //Thus only one object should be used.
    }
}
