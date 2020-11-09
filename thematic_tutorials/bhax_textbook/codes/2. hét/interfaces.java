public interface InterfaceA {
default public void method() {
 System.out.println("InterfaceA.method()");
 }
}

public interface InterfaceB {
default public void method() {
 System.out.println("InterfaceB.method()");
 }
}

public class Implementation implements InterfaceA, InterfaceB {
@Override
public void method() {
 InterfaceA.super.method();
 }
}
