import java.net.*; // paquete que contienen clases de red , todo lo necesario para comunicarme en red
import java.io.*; // paquete que contienen clases para E/S teclado y monitor

public class Server {

    public static void main(String[] args) throws IOException {

        int numeroPuerto = 5000;

        // Inside of the parentesis are declared all the resources to be closed
        try (
            ServerSocket socketdelServidor = new ServerSocket(numeroPuerto); // escuchando peticiones
            Socket socketdelCliente = socketdelServidor.accept();// se acepta la peticion
            PrintWriter escritor = new PrintWriter(socketdelCliente.getOutputStream(), true);
            BufferedReader lector = new BufferedReader(new InputStreamReader(socketdelCliente.getInputStream()));
        ){
            String linealeida;
            linealeida = lector.readLine();
            System.out.print("\nLa longitud del mensaje es: " + (linealeida.length() + 1));
            System.out.print("\nEl mensaje es: " + linealeida);
            System.out.println("\nEnviando adiós");
            escritor.println("\nAdios");
        } catch (IOException e) {
            System.out.println(" ocurrio una excepcion cuando intentamos escuchar " + numeroPuerto
                    + " o esperando por una conexicon");
            System.out.println(e.getMessage());
        }
    }
}
