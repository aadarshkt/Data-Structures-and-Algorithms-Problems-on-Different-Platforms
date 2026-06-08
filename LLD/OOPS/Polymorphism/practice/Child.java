public class Child extends Parent {

    //Constructor cannot be overridden although it may be overloaded.
    //Wrong -> void Parent(int age) { super.age = age; }

    public int age = 10;

    Child(int love) {
        super(love); //should be the very first line. //If parent has constructor, then you must use super.
    }

    //Method overriding

    //You cannot make override methods restrictive because at compiler that would be correct, but at runtime it may not be correct.

    @Override
    public void chooseCareer() {
        System.out.println("I will be become artist");
    }


    //static methods

    static public void walk(){
        System.out.println("Child is walking");
    }
}
