public class Practice {
    public static void main(String[] args){
        Parent c1 = new Child(10); //Upcasting.

        c1.chooseCareer(); //Decided at runtime

        c1.giftNeeded();

        c1.giftNeeded("Phone"); //Compile time decision of which function to call


//        c1.walk(); //Decided at compile time. //It belongs to class, class is parent here.

    // Why can't static methods be overridden?
    // Ans -> The basic reason for overriding is that we want different functions to be called
    // according to the objects created
    // at runtime, static methods are decided at compile and they belong to class, so we don't
    // override static methods. We will not get polymorphism.
        //It is method hiding instead because one method will always be hidden.

    System.out.println(c1.age); //data members are not overloaded, thus parent's value will be called. //Determined by reference type
        //Determined at compile time.



  }
}
