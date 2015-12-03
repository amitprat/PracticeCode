
1. Using Java Default Iterator

public class JavaDefaultIteratorEx {
  public static void main(String[] a) {
    Collection c = new ArrayList();
    c.add("1");
    c.add("2");
    c.add("3");
    /*
     * Way - 1
    Iterator it = c.iterator();
    while(it.hasNext()) {
      System.out.println(it.next());
    }
    */
    /*
    * Way - 2
    *for(Iterator it = c.iterator();it.hasNext();) {
      System.out.println(it.next());
    }
    */
    for(Object i : c) {
      System.out.println(i);
    }
  }
}
2. Implement iterator using nexted private class (Non Generic class)-
	

class HelloWorld implements Iterable {
	int arr[];
	int size = 0;
	
	//Initialize arr
	HelloWorld() {
	    arr = new int[10];
	}
	
	//implement the iterator method
	public Iterator iterator() {
		return new MyIterator();
	}
	
	private class MyIterator implements Iterator {
		
		public boolean hasNext() {
		    return (size < 10);
		}
		
		public Integer next() {
			return arr[size++];
		}
		public void remove() {
		}
	}
	
	public static void main(String args[]) {
		HelloWorld obj = new HelloWorld();
		
		for(Object i : obj)
			System.out.println(i);
	}
}
	
3. Implement iterator using nexted private class (Generic class)-
	

class HelloWorld<T> implements Iterable<T> {
  T arr[];
  int size = 0;
  int pos = 0;
  //Initialize arr
  HelloWorld() {
      arr = (T[])new Object[10];
  }
  void insert(T item) {
    arr[pos++] = item;
  }
  //implement the iterator method
  public Iterator iterator() {
   return new MyIterator();
  }
  
  private class MyIterator implements Iterator<T> {
   
   public boolean hasNext() {
       return (size < 10);
   }
   
   public T next() {
    return arr[size++];
   }
   public void remove() {
   }
  }
  
  public static void main(String args[]) {
   HelloWorld<String> obj = new HelloWorld();
   obj.insert("amit");
   for(String i : obj)
    System.out.println(i);
  }
}


4. Implement Iterator within object creation itself - 
 
public class javaIteratorIterableEx1 implements Iterable {

  // ...

  // Only arr is needed now as an instance variable.
  // int start;
  // int end;
  int[] arr;
  // myIterator it;
  javaIteratorIterableEx1() {
    arr = new int[10];
    for(int i=0;i<10;i++)
      arr[i] = i;
  }
  /**
   *  From interface Iterable.
   */
  public Iterator<Integer> iterator() {

    return new Iterator<Integer>() {
      // The next array position to return
      int pos = 0;

      public boolean hasNext() {
        return pos < arr.length;
      }

      public Integer next() {
        if(hasNext()) 
          return arr[pos++];
        else
          throw new NoSuchElementException();
      }

      public void remove() {
        throw new UnsupportedOperationException();
      }
    };
  }
  public static void main(String args[]) {
    javaIteratorIterableEx1 obj = new javaIteratorIterableEx1();
    Iterator it = obj.iterator();
    /*
     * Way - 1
    while(it.hasNext())
      System.out.println(it.next());
    */
    for(Object i : obj)
      System.out.println(i);
  }

}


5. Main Class Implementing both Iterable and Iterator : 

class HelloWorld<T> implements Iterable<T>, Iterator<T> {
  T arr[];
  int size = 0;
  int pos = 0;
  //Initialize arr
  HelloWorld() {
      arr = (T[])new Object[10];
  }
  public Iterator<T> iterator() {
    return this;
  }
  void insert(T item) {
    arr[pos++] = item;
  }
   public boolean hasNext() {
       return (size < 10);
   }
   
   public T next() {
    return arr[size++];
   }
   public void remove() {
   }
  
  public static void main(String args[]) {
   HelloWorld<String> obj = new HelloWorld();
   obj.insert("amit");
   for(String i : obj)
    System.out.println(i);
  }
}
 
 
