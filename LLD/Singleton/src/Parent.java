public class Parent {
    String name; //to prevent warning for utility classes
    private Parent(){

    }

    static Parent instance;

    //static is important because you can't create instance of parent class as constructor is private.
    public static Parent getInstance(){
        if(instance == null){
            instance = new Parent();
        }

        return instance;
    }
}
