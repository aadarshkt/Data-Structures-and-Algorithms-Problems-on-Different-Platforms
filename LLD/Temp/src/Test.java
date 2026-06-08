public class Test {

    class Testtype {
        String name;

        public Testtype(String name){
            this.name = name;
        }
    }

    public void func() {
        Testtype a = new Testtype("stress");
        System.out.println(a.name);
    }

    public static void main(String[] args) {
        Test newTest = new Test();
        newTest.func();
    }
}
