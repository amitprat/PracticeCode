imprt java.io.*;
import java.net.*;

public class socketClient {
  public static void main(String args[]) {
    String ip = args[0];
    int port = Integer.parseInt(args[1]);
    try {
      Socket sock = new Socket (ip, port );
      InputStream in = new InputStreamReader ( sock.getInputStream() ); // for comand line input - System.in
      BufferedReader br = new BufferedReader( in );
      String line;
      
      while( (line = br.readLine())) {
        System.out.println(line);
      }
      sock.close();
    }catch( Exception e ) {
      System.out.println(e.toString());
      System.out.println(e.printStatckTrace() );
    } finally {
      sock.close();
    }
  }
}
