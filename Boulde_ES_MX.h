/*
 *  PAQUETE DE DIALOGOS EN: ESPAÑOL MÉXICO
 *  RESPETAR LOS CARACTERES DE SALTO DE LINEA '\n' Y DE FORMATO:
 *  RESPETA MaYuScUlAs Y mInUsCuLaS
 *  EJEMPLO: '%d'.
 *
 *  ==== SOLO TRADUCIR LOS TEXTOS ====
 */
#ifndef EDLGS_H
#define EDLGS_H

const char *initDlg = "Juegoeconomía; Teclea 'help' para recibir ayuda. Para salir del juego teclea 'exit'.\n";
const char *emptyCmdDlg = "Incorrecto: Entrada vacia, tecle algo\n";
const char *doubleSDlg = "Incorrecto: Doble espacio, intente de nuevo\n";

const char *confirmExitDlg = "Esta seguro de que quiere salir (Recuerde guardar primero)\nsi|no: ";
const char *yes = "si";
const char *cancelledDlg = "Cancelado\n";

const char *helpDlg = "Comandos\n"
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
                      " make     Crea un objeto\n";

const char *statsDlg = "Estadisticas:\n"
                       " Nivel: %d\n"
                       " Dinero: %d\n"
                       " Experiencia: %d\n";
const char *statsInveDlg = "Inventario\n";

const char *workGainDlg = "Has ganado: $%d + %d xp\n";
const char *levelUpDlg = "Subiste de nivel %d\n";

const char *savedDataDlg = "Datos guardados\n";
const char *loadedDataDlg = "Datos cargados\n";

const char *resetConfirmDlg = "Quieres reiniciar tus datos\nPELIGRO: SE BORARAN PARA SIEMPRE!\nyes|no: ";
const char *resetingDlg = "Reiniciando...\n";

const char *shopDlg = " ID |Name    |Price |ID |Name    |Price\n"
                      " 1  |Palo    |$4    |2  |Roca    |$6\n"
                      " 3  |Madera  |$12   |4  |Piedra  |$18\n"
                      " 5  |Tablas  |$26   |6  |Carbon  |$35\n"
                      " 7  |Hierro  |$56   |8  |Cobre   |$78\n";

const char *stick = "palo";
const char *rock = "roca";
const char *wood = "madera";
const char *stone = "piedra";
const char *planks = "tablas";
const char *coal = "carbon";
const char *iron = "hierro";
const char *copper = "cobre";

const char *buyDlg = "Selecciona un objeta a comprar (teclea '.c' para cancelar)\nobjeto: ";
const char *unknownItemDlg = "Error: objeto '%s' desconocido\n";
const char *amountDlg = "cantidad: ";
const char *tinyAmountDlg = "Amount to tiny\n";

const char *lvlRequieredDlg = "Nivel %d en adelante\n";
const char *enoughMoney = "Dinero insuficiente\n";
const char *unableBuy = "Error: recolecta $%d mas para comprarlo x%d\n";
const char *buied = "Comprado %d %s(s) -%d\n";

const char *commingSoonDlg = "Comming soon\n";

const char *unknownCmdDlg = "Error unknown command\n";

const char *programFinishDlg = "Comming soon\n";

#endif // EDLGS_H