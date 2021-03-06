import java.io.*;
import java.net.*;

public class ClienteTocToc {
    public static void main(String[] args) throws IOException {

        if (args.length != 2) {
            System.err.println(
                "Uso desde consola: java ClienteTocToc <ip de host (computadora)> <numero puerto>");
            System.exit(1);
        }

        // guardamos el nombre del host
        String nombreHost = args[0];

        // convertimos el numero de puerto
        int numeroPuerto = Integer.parseInt(args[1]);

        // declaramos un socket para recibir y enviar datos
        Socket TocTocSocket = null;
        //declaramos un escritor para escribir los datos que se enviaran en el socket
        PrintWriter EscritorEnSocket = null;
        // declaramos un lector de flujo de texto (el flujo es una secuencia de entrada de caracteres, 
        //almacenando caracteres en un buffer para proporcionar una lectura eficiente 
        //de caracteres, líneas y matrices.
        BufferedReader LectorDeSocket = null;

        try {
            //abrimos el socket TocTocSocket para hacer peticiones al servidor
            TocTocSocket = new Socket(nombreHost, numeroPuerto);
            System.out.println("Estamos listos en el puerto " + numeroPuerto);
            //asignamos a lector y escritor el flujo de datos del socket
            EscritorEnSocket = new PrintWriter(TocTocSocket.getOutputStream(), true);
            LectorDeSocket = new BufferedReader(new InputStreamReader(TocTocSocket.getInputStream()));
        } catch (UnknownHostException e) {
            System.err.println("No conozco al host " + nombreHost);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("No se pudo obtener E/S para la conexion" + nombreHost);
            System.exit(1);
        }
// abrimos un lector , para leer el texto desde consola 
        BufferedReader EntradaTeclado = new BufferedReader(new InputStreamReader(System.in));
        //declaramos cadenas para almacenar el texto recibido del servidor 
        //y otra para el texto recibido desde consola por el usuario
        String DelServidor;
        String DelUsuario;
// leemos lo que dice el servidor , y si hay algo escrito procedemos a ingresar al ciclo while
        while ((DelServidor = LectorDeSocket.readLine()) != null) {
            System.out.println("El Servidor dice: " + DelServidor);
           // si el usuario escribe Adios, significa que hay que cerrar la transmision de datos
            if (DelServidor.equals("Adios."))
                break;
// leeemos desde la consola del usuario
            DelUsuario = EntradaTeclado.readLine();
            // si si leimos algo ( quiere decir que el usuario escribio algo) 
	    if (DelUsuario != null) {
                System.out.println("El Cliente dice: " + DelUsuario);
                EscritorEnSocket.println(DelUsuario);
	    }
        }

        EscritorEnSocket.close();
        LectorDeSocket.close();
        EntradaTeclado.close();
        TocTocSocket.close();
    }
}
