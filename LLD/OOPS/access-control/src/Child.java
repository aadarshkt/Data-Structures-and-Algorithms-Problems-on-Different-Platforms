public class Child extends Parent {
    void print(){
        //child can access  protected.
        System.out.println(this.password);
    }
}
