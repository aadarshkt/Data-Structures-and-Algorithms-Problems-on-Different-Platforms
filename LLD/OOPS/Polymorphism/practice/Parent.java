public class Parent {

    public int age = 40;

    public int amountOfLove = 0;
    Parent(int love){
        this.amountOfLove = love;
    }
    public void chooseCareer(){
    System.out.println("I am will become doctor");
    }

    void giftNeeded() {
        System.out.println("I need sound system");
    }

    public void giftNeeded(String s){
        System.out.println("Parent need gift " + s);
    }

    static public void walk() {
    System.out.println("Parent is walking");
    }


}
