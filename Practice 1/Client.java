

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        
        String nombreHost = "127.0.0.1";
        int numeroPuerto = 5000;

        try (
            Socket socketEco = new Socket(nombreHost, numeroPuerto);
            PrintWriter escritor = new PrintWriter(socketEco.getOutputStream(), true);
            
            BufferedReader lector = new BufferedReader(new InputStreamReader(socketEco.getInputStream()));
            BufferedReader teclado = new BufferedReader( new InputStreamReader(System.in))
        ) {
            String mensaje;
            mensaje = teclado.readLine();
            System.out.println("Por favor escriba su mensaje: ");
            escritor.println(mensaje);
            String linealeida;
            linealeida = lector.readLine();
            System.out.print("\nLa longitud del mensaje es: " + (linealeida.length() + 1));
            System.out.print("\nEl mensaje es: " + linealeida);
        } catch (UnknownHostException e) {
            System.err.println("No conozco al host " + nombreHost);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("no se pudo obtener E/S para la conexion " +
                nombreHost);
            System.exit(1);
        } 
    }
}
