/*
*  PAQUETE DE DIALOGOS EN: ESPAÑOL MÉXICO
*  RESPETAR LOS CARACTERES DE SALTO DE LINEA '\n' Y DE FORMATO:
*  EJeMPLO: '%d'.
*/
#ifndef EDLGS_H
#define EDLGS_H

const char * initDlg      = "Juegoeconomía; Teclea 'help' para recibir ayuda."
                            "Para salir del juego teclea 'exit'.";
const char * emptyCmdDlg  = "Incorrecto: Entrada vacia, tecle algo";
const char * doubleSDlg   = "Incorrecto: Doble espacio, intente de nuevo";
const char * confirmDlg   = "Esta seguro de que quiere salir (Recuerde guardar primero)\nyes|no: ";
const char * cancelledDlg = "Cancelado";
const char * helpDlg      = "Comandos\n"
                            " exit     Cierra el programa\n"
                            " help     Muestra esta lista\n"
                            " stats    Muestra el estado del jugador\n"
                            " work     Obtiene dinero en base al nivel\n"
                            " save     Guarda los datos del jugador\n"
                            " load     Carga los datos del jugador\n"
                            " reset    Reinicia los datos del jugador: USE ESTO CON CUIDADO\n"
                            " items    Muestra todos los objetos comprables\n"
                            " buy      Compra un objeto\n"
                            " sell     Vende un objeto\n"
                            " make     Crea un objeto";
const char * statsDlg     = "Estadisticas:\n"
                            " Nivel: %d\n"
                            " Dinero: %d\n"
                            " Experiencia: %d\n";
const char * statsInveDlg = "Inventario";
const char * workGain     = "Has ganado: $%d + %d xp\n";
const char * levelUp      = "Subiste de nivel %d\n";
const char * savedData    = "Datos guardados";
const char * loadedData   = "Datos cargados";
#endif // EDLGS_H