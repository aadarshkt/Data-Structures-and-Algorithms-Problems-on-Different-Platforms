package Creational.Singleton.Solution;

public class AppSettings {

    //Step 1: Create private static instance of the class.
    private static AppSettings instance;

    private String databaseUrl;
    private String apiKey;

    //Step 2: Make the constructor private
    private AppSettings() {
        databaseUrl = "jdbc:mysql://localhost:3306/mydatabase";
        apiKey = "54321";
    }

    //Step 3: Return that single instance;
    public static AppSettings getInstance() {
        if(instance == null){
            instance = new AppSettings();
        }
        return instance;
    }

    public String getDatabaseUrl() {
        return databaseUrl;
    }

    public String getApiKey() {
        return apiKey;
    }

    public void setDatabaseUrl(String databaseUrl) {
        this.databaseUrl = databaseUrl;
    }

    public void setApiKey(String apiKey) {
        this.apiKey = apiKey;
    }
}
