package Creational.Singleton.Problem;

public class AppSettings {
    private String databaseUrl;
    private String apiKey;

    public AppSettings() {
        databaseUrl = "jdbc:mysql://localhost:3306/mydatabase";
        apiKey = "54321";
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