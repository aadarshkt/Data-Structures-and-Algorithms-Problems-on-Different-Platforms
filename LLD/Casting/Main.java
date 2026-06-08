public class Main {
    public static void main(String[] args){
        Animal animal = new Cat(); //Upcasting is implicit.

        animal.makeSound(); //Will run cat sound
        System.out.println(animal.hasDNA());

        //animal.jump() not available.

//        if(animal instanceof Cat) {
//           Cat cat = (Cat) animal; //Down casting.
//
//           cat.jump();
//        }

        //WHy you would upcasting, because it allows you to access methods of parent class without overriding.


    }
}
