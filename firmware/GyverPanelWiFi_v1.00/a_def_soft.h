// Определения программных констант и переменных (параметры эффектов и т.п.)

// При запуске микроконтроллера выполняется инициализация всех параметров значениями, сохраненными в EEPROM (функция loadSettings() в eeprom.ino)
// При этом если флаг EEPROM_OK в первой строке файла eeprom.ino был изменен и не совпадает со считанными яз ячейки #1 значением -
// выполняется инициализация параметров значениями по умолчанию (функция loadSettings() в eeprom.ino, ветвь if (isInitialized) -> false )
// Заполните в этом блоки значения переменных желаемыми.

#define DEBUG 0                  // Отладочный вывод 0 - отключен, 1 - включен

// ******************* ОПРЕДЕЛЕНИЯ ПАРАМЕТРОВ ЭФФЕКТОВ *********************

// Список и порядок эффектов, передаваймый в приложение на смартфоне. Данный список попадает в комбобокс выбора, 
// чей индекс передается из приложения в контроллер матрицы для выбора, поэтому порядок должен соответствовать 
// списку эффектов, определенному выше
#define EFFECT_LIST F("Лампа,Снегопад,Кубик,Радуга,Пейнтбол,Огонь,The Matrix,Шарики,Звездопад,Конфетти,Часы с датой," \
                      "Цветной шум,Облака,Лава,Плазма,Радужные переливы,Полосатые переливы,Зебра,Шумящий лес,Морской прибой,Смена цвета," \
                      "Светлячки,Водоворот,Часы,Циклон,Рассвет")

// ID эффектов
#define MC_FILL_COLOR            0
#define MC_SNOW                  1
#define MC_BALL                  2
#define MC_RAINBOW               3
#define MC_PAINTBALL             4
#define MC_FIRE                  5
#define MC_MATRIX                6
#define MC_BALLS                 7
#define MC_STARFALL              8
#define MC_SPARKLES              9
#define MC_TEXT                 10  // после удалить (заменить на другой эффект)
#define MC_NOISE_MADNESS        11
#define MC_NOISE_CLOUD          12
#define MC_NOISE_LAVA           13
#define MC_NOISE_PLASMA         14
#define MC_NOISE_RAINBOW        15
#define MC_NOISE_RAINBOW_STRIP  16
#define MC_NOISE_ZEBRA          17
#define MC_NOISE_FOREST         18
#define MC_NOISE_OCEAN          19
#define MC_COLORS               20
#define MC_LIGHTERS             21
#define MC_SWIRL                22
#define MC_CLOCK                23  // после удалить (заменить на другой эффект)
#define MC_CYCLON               24
#define MC_DAWN_ALARM           26

#define MAX_EFFECT              26         // количество эффектов, определенных в прошивке
#define MAX_SPEC_EFFECT         11         // количество эффектов быстрого доступа определенных в прошивке -> 0..10

// ---------------------------------
#define MC_DAWN_ALARM_SPIRAL   253         // Специальный режим, вызывается из DEMO_DAWN_ALARM для ламп на круговой матрице - огонек по спирали
#define MC_DAWN_ALARM_SQUARE   254         // Специальный режим, вызывается из DEMO_DAWN_ALARM для плоских матриц - огонек по спирали на плоскости матрицы
// ---------------------------------

// ****************** ОПРЕДЕЛЕНИЯ ПАРАМЕТРОВ БУДИЛЬНИКА ********************

#if (USE_MP3 == 1)
// SD карточка в MP3 плеере (DFPlayer) содержить в корне две папки - "1" и "2"
// Папка "1" содержит MP3 файлы звуков, проигрываемых при наступлении события будильника
// Папка "2" содержит MP3 файлы звуков, проигрываемых при наступлении события рассвета
// DFPlayer не имеет возможности считывать имена файлов, только возможность получить количество файлов в папке.
// Команда на воспроизведение звука означает - играть файл с индексом (номером) N из папки M
// Номера файлов определяются таблицей размещения файлов SD-карты (FAT)  и формируются в порядке очереди записи файлов на чистую флэшку
// Так, файл записанный в папку первым получает номер 1, вторыи - 2 и так далее и ника не зависит от имен файлов
// Данные массивы содержат отображаемые в приложении имена звуков в порядке, соответствующем нумерации записанных в папки файлов.
#define ALARM_SOUND_LIST F("One Step Over,In the Death Car")            // Список звука для комбобокса "Звук будильника" в приложении на смартфоне
#define DAWN_SOUND_LIST  F("Птицы,Гроза,Прибой,Дождь,Ручей,Мантра")     // Список звука для комбобокса "Звук рассвета" в приложении на смартфоне
#endif

// ********************* ОПРЕДЕЛЕНИЯ ПАРАМЕТРОВ ЧАСОВ **********************

#define D_CLOCK_SPEED 100     // скорость перемещения эффекта часов по умолчанию (мс)
#define D_CLOCK_SPEED_MIN 2
#define D_CLOCK_SPEED_MAX 255

byte CLOCK_SIZE = 0;                      // Размер горизонтальных часов: 0 - авто; 1 - цифры 3x5; 2 - цифры 5х7
byte CLOCK_ORIENT = 0;                    // Ориентация отображения часов: 0 горизонтальные, 1 вертикальные (только для режима часов с цифрами 3х5; Часы шрифтом 5x7 всегда горизонтальные
byte CLOCK_MOVE_DIVIDER = 3;              // Делитель такта таймера эффектов для движения часов оверлея (режим прокручивания часов по горизонтали)
byte CLOCK_MOVE_CNT = CLOCK_MOVE_DIVIDER; // Текущее значения счетчика сдвига 

// Макрос центрирования отображения часов на матрице
#define CLOCK_X_H1 (byte((WIDTH - (4*3 + 3*1)) / 2.0 + 0.51))      // 4 цифры * (шрифт 3 пикс шириной) 3 + пробела между цифрами), /2 - в центр 
#define CLOCK_Y_H1 (byte((HEIGHT - (1*5)) / 2.0 + 0.51))           // Одна строка цифр 5 пикс высотой  / 2 - в центр
#define CLOCK_X_H2 (byte((WIDTH - (4*5 + 2*1 + 4)) / 2.0 + 0.51))  // 4 цифры * (шрифт 5 пикс шириной) 3 + пробела между цифрами) + 4 - ширина точек, /2 - в центр 
#define CLOCK_Y_H2 (byte((HEIGHT - (1*7)) / 2.0 + 0.51))           // Одна строка цифр 7 пикс высотой  / 2 - в центр
#define CLOCK_X_V  (byte((WIDTH - (2*3 + 1)) / 2.0 + 0.51))        // 2 цифры * (шрифт 3 пикс шириной) 1 + пробел между цифрами) /2 - в центр
#define CLOCK_Y_V  (byte((HEIGHT - (2*5 + 1)) / 2.0 + 0.51))       // Две строки цифр 5 пикс высотой + 1 пробел между строкми / 2 - в центр

// Макрос центрирования отображения календаря на матрице
#define CAL_X      (byte((WIDTH - (4*3 + 1)) / 2.0))               // 4 цифры * (шрифт 3 пикс шириной) 1 + пробел между цифрами) /2 - в центр
#define CAL_Y      (byte((HEIGHT - (2*5 + 1)) / 2.0))              // Две строки цифр 5 пикс высотой + 1 пробел между строкми / 2 - в центр

byte clockSpeed = D_CLOCK_SPEED;            // Скорость прокрутки часов
byte c_size = 0;                            // тип часов: 0 - авто; 1 - шрифт 3x5; 2 - шрифт 5х7; вычисляется в зависимости от настроек и параметров матрицы 

// Позиции отображения статических часов; Вычисляется в зависимости от выбранного шрифта часов 3x5 или 5x7, вертикальные/горизонтальные
byte   CALENDAR_X  = CAL_X;                 // По умолчанию - 3x5, горизонтальные - позиция вывода календаря по X
byte   CALENDAR_Y  = CAL_Y;                 // По умолчанию - 3x5, горизонтальные - позиция вывода календаря по Y
byte   CLOCK_X     = CLOCK_X_H1;            // По умолчанию - 3x5, горизонтальные - позиция вывода часов по X
byte   CLOCK_Y     = CLOCK_Y_H1;            // По умолчанию - 3x5, горизонтальные - позиция вывода часов по Y

int8_t CLOCK_XC    = CLOCK_X;               // Текущая позиция часов оверлея по оси Х 
int8_t CALENDAR_XC = CALENDAR_X;            // Текущая позиция календаря оверлея по оси Х 

// Часы могут отображаться: 
// - вертикальные при высоте матрицы >= 11 и ширине >= 7; 
// - горизонтальные при ширене матрицы >= 15 и высоте >= 5
//   минимальная ширина горизонтальных часов - 15 символов, т.к если большие часы не влазят по ширине - автоматически используются маленькие часы
bool allowVertical   = WIDTH >= 7  && HEIGHT >= 11;
bool allowHorizontal = WIDTH >= 15 && HEIGHT >= 7;

byte COLOR_MODE = 0;                     // Режим цвета часов
//                                         0 - монохром
//                                         1 - радужная смена (каждая цифра)
//                                         2 - радужная смена (часы, точки, минуты)
//                                         3 - заданные цвета (часы, точки, минуты) - HOUR_COLOR, DOT_COLOR, MIN_COLOR в clock.ino

byte COLOR_TEXT_MODE = 0;                // Режим цвета часов бегущей строки и самой бегущей строки
//                                         0 - монохром
//                                         1 - радужная смена (каждая цифра)
//                                         2 - каждая цифра свой цвет

byte    nightClockColor = 0;             // Цвет ночных часов: 0 - R; 1 - G; 2 - B; 3 - C; 4 - M; 5 - Y;
bool    needTurnOffClock = false;        // Выключать индикатор часов TM1637 при выключении устройства (true); если False - при отключении панели индикатор TM1637 продолжает показывать текущее время

boolean showDateInClock = true;          // Показывать дату при отображении часов
byte    showDateDuration = 3;            // на 3 секунд
byte    showDateInterval = 240;          // через каждые 240 секунд
byte    showDateState = false;           // false - отображаются часы; true - отображается дата
long    showDateStateLastChange = 0;     // Время, когда отображение часов сменилось на отображение календаря и наоборот

int8_t  hrs = 0, mins = 0;               // Для получения текущего времени. Инициализировано как 01.01.1970 00:00
int8_t  secs = 0, aday = 1, amnth = 1;
int16_t ayear = 1970;
bool    dotFlag;                         // флаг: в часах рисуется точки 

// ************************ НАСТРОЙКИ БЕГУЩЕЙ СТРОКИ ***********************

#define MIRR_V 0                         // отразить текст по вертикали (0 / 1)
#define MIRR_H 0                         // отразить текст по горизонтали (0 / 1)

#define LET_WIDTH 5                      // ширина буквы шрифта
#define LET_HEIGHT 8                     // высота буквы шрифта
#define SPACE 1                          // пробел

boolean fullTextFlag = false;            // флаг: текст бегущей строки показан полностью (строка убежала)

// *************************** ПОДКЛЮЧЕНИЕ К СЕТИ **************************

// Внимание!!! Если вы меняете эти значения ПОСЛЕ того, как прошивка уже хотя бы раз была загружена в плату и выполнялась,
// чтобы изменения вступили в силу нужно также изменить значение константы EEPROM_OK в первой строке в файле eeprom.ino 

#define DEFAULT_NTP_SERVER "ru.pool.ntp.org" // NTP сервер по умолчанию "time.nist.gov"
#define DEFAULT_AP_NAME "PanelAP"        // Имя точки доступа по умолчанию 
#define DEFAULT_AP_PASS "12341234"       // Пароль точки доступа по умолчанию
#define NETWORK_SSID ""                  // Имя WiFi сети
#define NETWORK_PASS ""                  // Пароль для подключения к WiFi сети

// ---------------------------------------------------------------

WiFiUDP udp;
                                         // к длине +1 байт на \0 - терминальный символ. Это буферы для загрузки имен/пароля из EEPROM. Значения задаются в defiine выше
char   apName[11] = "";                  // Имя сети в режиме точки доступа
char   apPass[17] = "";                  // Пароль подключения к точке доступа
char   ssid[25]   = "";                  // SSID (имя) вашего роутера (конфигурируется подключением через точку доступа и сохранением в EEPROM)
char   pass[17]   = "";                  // пароль роутера
byte   IP_STA[]   = {192, 168, 0, 116};  // Статический адрес в локальной сети WiFi по умолчанию при первом запуске. Потом - загружается из настроек, сохраненных в EEPROM
unsigned int localPort = 2390;           // локальный порт на котором слушаются входящие команды управления от приложения на смартфоне, передаваемые через локальную сеть

// ---------------------------------------------------------------

bool   useSoftAP = false;                // использовать режим точки доступа
bool   wifi_connected = false;           // true - подключение к wifi сети выполнена  
bool   ap_connected = false;             // true - работаем в режиме точки доступа;
bool   wifi_print_ip = false;            // Включен режим отображения текущего IP на индикаторе TM1637
bool   wifi_print_ip_text = false;       // Включен режим отображения текущего IP на матрице
byte   wifi_print_idx = 0;               // Индекс отображаемой на индикаторе TM1637 тетрады IP адреса
String wifi_current_ip = "";             // Отображаемый в бегущей строке IP адрес лампы

// **************** СИНХРОНИЗАЦИЯ ЧАСОВ ЧЕРЕЗ ИНТЕРНЕТ ********************

IPAddress timeServerIP;
#define NTP_PACKET_SIZE 48               // NTP время - в первых 48 байтах сообщения
uint16_t SYNC_TIME_PERIOD = 60;          // Период синхронизации в минутах по умолчанию
byte packetBuffer[NTP_PACKET_SIZE];      // буфер для хранения входящих и исходящих пакетов NTP

int8_t timeZoneOffset = 7;               // смещение часового пояса от UTC
long   ntp_t = 0;                        // Время, прошедшее с запроса данных с NTP-сервера (таймаут)
byte   ntp_cnt = 0;                      // Счетчик попыток получить данные от сервера
bool   init_time = false;                // Флаг false - время не инициализировано; true - время инициализировано
bool   refresh_time = true;              // Флаг true - пришло время выполнить синхронизацию часов с сервером NTP
bool   useNtp = true;                    // Использовать синхронизацию времени с NTP-сервером
char   ntpServerName[31] = "";           // Используемый сервер NTP

// *********************** ДЛЯ БУДИЛЬНИКА-РАССВЕТ ************************

bool   isAlarming = false;               // Сработал будильник "рассвет"
bool   isPlayAlarmSound = false;         // Сработал настоящий будильник - играется звук будильника
bool   isAlarmStopped = false;           // Сработавший будильник "рассвет" остановлен пользователем

byte   alarmWeekDay = 0;                 // Битовая маска дней недели будильника
byte   alarmDuration = 1;                // Проигрывать звук будильнике N минут после срабатывания (по окончанию рассвета)

byte   alarmHour[7]   = {0,0,0,0,0,0,0}; // Часы времени срабатывания будильника по дням недели
byte   alarmMinute[7] = {0,0,0,0,0,0,0}; // Минуты времени срабатывания будильника по дням недели

int8_t dawnHour = 0;                     // Часы времени начала рассвета
int8_t dawnMinute = 0;                   // Минуты времени начала рассвета
byte   dawnWeekDay = 0;                  // День недели времени начала рассвета (0 - выключено, 1..7 - пн..вс)
byte   dawnDuration = 0;                 // Продолжительность "рассвета" по настройкам
byte   realDawnDuration = 0;             // Продолжительность "рассвета" по вычисленому времени срабатывания будильника
byte   alarmEffect = MC_DAWN_ALARM;      // Какой эффект используется для будильника "рассвет". Могут быть обычные эффекты - их яркость просто будет постепенно увеличиваться

// **************************** MP3 ПЛЕЕР *****************************

bool isDfPlayerOk = false;               // MP3-Player корректно инициализирован и готов к использованию

#if (USE_MP3 == 1)
#if defined(ESP8266)
//SoftwareSerial mp3Serial(SRX, STX);    // Используйте этот вариант, если у вас библиотека ядра ESP8266 версии 2.5.2
  SoftwareSerial mp3Serial;              // Используйте этот вариант, если у вас библиотека ядра ESP8266 версии 2.6.x
#endif
#if defined(ESP32)
  SoftwareSerial mp3Serial;
#endif

DFRobotDFPlayerMini dfPlayer; 
int16_t  alarmSoundsCount = 0;           // Кол-во файлов звуков в папке '01' на SD-карте
int16_t  dawnSoundsCount = 0;            // Кол-во файлов звуков в папке '02' на SD-карте
byte     soundFolder = 0;                // Текущая используемая папка со звуками 
byte     soundFile = 0;                  // Текущий используемый файл звука в папке
int8_t   fadeSoundDirection = 1;         // направление изменения громкости звука: 1 - увеличение; -1 - уменьшение
byte     fadeSoundStepCounter = 0;       // счетчик шагов изменения громкости, которое осталось сделать
bool     useAlarmSound = false;          // Использовать звуки в будильнике
int8_t   alarmSound = 0;                 // Звук будильника - номер файла в папке SD:/01 [-1 не использовать; 0 - случайный; 1..N] номер файла
int8_t   dawnSound = 0;                  // Звук рассвета   - номер файла в папке SD:/02 [-1 не использовать; 0 - случайный; 1..N] номер файла
byte     maxAlarmVolume = 30;            // Максимальная громкость будильника (1..30)
#endif

// ************************* КНОПКА УПРАВЛЕНИЯ *************************

// GButton butt(PIN_BTN, LOW_PULL, NORM_OPEN); // Для сенсорной кнопки
GButton butt(PIN_BTN, HIGH_PULL, NORM_OPEN);   // Для обычной кнопки

bool     isButtonHold = false;           // Кнопка нажата и удерживается
byte     bCounter = 0;                   // Счетчик нажатия на кнопку

// ************************** Дисплей TM1637 **************************

TM1637Display display(CLK, DIO);
bool     aDirection = true;              // Направление счетчика изменения яркости, отображаемом на индикаторе при регулировке
byte     aCounter = 0;                   // Текущая яркость индикатора при плавном изменении яркости
uint32_t fade_time;                      // Для плавного изменения яркости индикатора при сработавшем будильнике

// ******************** ВКЛЮЧЕНИЕ РЕЖИМОВ ПО ВРЕМЕНИ *********************

bool     AM1_running = false;            // Режим 1 по времени - работает
byte     AM1_hour = 0;                   // Режим 1 по времени - часы
byte     AM1_minute = 0;                 // Режим 1 по времени - минуты
int8_t   AM1_effect_id = -3;             // Режим 1 по времени - ID эффекта или -3 - выключено (не используется); -2 - выключить матрицу (черный экран); -1 - ночные часы, 0 - случайный, 1 и далее - эффект EFFECT_LIST
bool     AM2_running = false;            // Режим 2 по времени - работает
byte     AM2_hour = 0;                   // Режим 2 по времени - часы
byte     AM2_minute = 0;                 // Режим 2 по времени - минуты
int8_t   AM2_effect_id = -3;             // Режим 2 по времени - ID эффекта или -3 - выключено (не используется); -2 - выключить матрицу (черный экран); -1 - ночные часы, 0 - случайный, 1 и далее - эффект EFFECT_LIST
bool     AM3_running = false;            // Режим 3 по времени - работает
byte     AM3_hour = 0;                   // Режим 3 по времени - часы
byte     AM3_minute = 0;                 // Режим 3 по времени - минуты
int8_t   AM3_effect_id = -3;             // Режим 3 по времени - ID эффекта или -3 - выключено (не используется); -2 - выключить матрицу (черный экран); -1 - ночные часы, 0 - случайный, 1 и далее - эффект EFFECT_LIST
bool     AM4_running = false;            // Режим 4 по времени - работает
byte     AM4_hour = 0;                   // Режим 4 по времени - часы
byte     AM4_minute = 0;                 // Режим 4 по времени - минуты
int8_t   AM4_effect_id = -3;             // Режим 4 по времени - ID эффекта или -3 - выключено (не используется); -2 - выключить матрицу (черный экран); -1 - ночные часы, 0 - случайный, 1 и далее - эффект EFFECT_LIST

// ************************* ПРОЧИЕ ПЕРЕМЕННЫЕ *************************

#if (SMOOTH_CHANGE == 1)
  byte fadeMode = 4;                     // Фаза режима плавной смены эффекта
  boolean modeDir;                       // Направление перехода к следующему / предыдущему режиму
#endif

// ---------------------------------------------------------------

#define  D_EFFECT_SPEED       80         // скорость эффектов по умолчанию (мс)
#define  D_EFFECT_SPEED_MIN    0         // пределы регулировки скорости
#define  D_EFFECT_SPEED_MAX  255

// ---------------------------------------------------------------

#define  AUTOPLAY_PERIOD 60              // время между авто сменой режимов (секунды)
#define  IDLE_TIME 30                    // время бездействия (в минутах, по умолчанию) после которого запускается автосмена режимов, если разрешена в настройках
#define  SMOOTH_CHANGE 0                 // плавная смена режимов через чёрный

// ---------------------------------------------------------------

bool     eepromModified = false;         // флаг: EEPROM изменен, требует сохранения

// ---------------------------------------------------------------

uint32_t globalColor      = 0xffffff;    // цвет панели в режиме "Лампа" по умолчанию
uint32_t globalClockColor = 0xffffff;    // цвет часов в режиме MC_COLOR - режим цвета "Монохром" по умолчанию
uint32_t globalTextColor  = 0xffffff;    // цвет часов бегущей строки MC_TEXT в режиме цвета "Монохром" по умолчанию

// ---------------------------------------------------------------

bool     AUTOPLAY = false;               // false выкл / true вкл автоматическую смену режимов (откл. можно со смартфона)
bool     specialMode = false;            // Спец.режим, включенный вручную со смартфона или с кнопок быстрого включения режима
bool     specialClock = false;           // Отображение часов в спец.режиме
byte     specialBrightness = 1;          // Яркость в спец.режиме

bool     isTurnedOff = false;            // Включен черный экран (т.е всё выключено) 
bool     isNightClock = false;           // Включен режим ночных часов

int8_t   specialModeId = -1;             // Номер текущего спецрежима
int8_t   manualModeId = -1;              // Номер текущего режима

bool     useRandomSequence = true;       // Флаг: случайный выбор режима
byte     formatClock = 0;                // Формат часов в бегущей строке: 0 - только часы; 1 - часы и дата кратко; 2 0 часы и дата строкой
bool     overlayEnabled = true;          // Доступность оверлея часов / бегущей строки поверх эффектов
bool     overlayDelayed = false;         // используется для указания был ли оверлей на пердыдцщем цикле отрисовки
int8_t   y_overlay_low  = 0;             // Вычисленная позицуия оверлея матрицы - во всю ширину, область отображения текста бегущей строки / часов / календаря
int8_t   y_overlay_high = 0;


// ---------------------------------------------------------------

// Сервер не может инициировать отправку сообщения клиенту - только в ответ на запрос клиента
// Следующие две переменные хранят сообщения, формируемые по инициативе сервира и отправляются в ответ на ближайший запрос от клиента,
// например в ответ на периодический ping - в команде sendAcknowledge();

String   cmd95 = "";                     // Строка, формируемая sendPageParams(95) для отправки по инициативе сервера
String   cmd96 = "";                     // Строка, формируемая sendPageParams(96) для отправки по инициативе сервера

// ---------------------------------------------------------------

byte     globalBrightness = BRIGHTNESS;  // текущая яркость бегущей строки и часов (общая)
byte     contrast = 255;                 // контрастность эффектов по отношению к яркости часов / бегущей строки (общей яркости) => 0.255 -> 10..100%
bool     brightDirection = false;        // true - увеличение яркости; false - уменьшение яркости при регулировке кнопкой
byte     effectBrightness = 255;         // реальная величина яркости, применяемая к эффектам. Вычисляется как процент к глобальной яркости

// ---------------------------------------------------------------

int      effectSpeed = D_EFFECT_SPEED;   // скрость изменения эффекта (по умолчанию)
byte     effectScaleParam[MAX_EFFECT];   // Динамический параметр эффекта, параметр #1
byte     effectScaleParam2[MAX_EFFECT];  // Динамический параметр эффекта, параметр #2
bool     BTcontrol = false;              // флаг: true - ручное управление эффектами; false - в режиме Autoplay
bool     loadingFlag = true;             // флаг: инициализация параметров эффекта

// ---------------------------------------------------------------

uint32_t idleTime = ((long)IDLE_TIME * 60 * 1000);      // минуты -> миллисек
uint32_t autoplayTime = ((long)AUTOPLAY_PERIOD * 1000); // секунды -> миллисек
bool     idleState = true;                              // флаг холостого режима работы
uint32_t autoplayTimer;                                 // время до автоматического перехода в демо-режим

// ---------------------------------------------------------------

int8_t   thisMode = 0;                    // текущий режим
byte     modeCode;                        // тип текущего эффекта: 0 бегущая строка, 1 часы, 2 игры, 3 нойс маднесс и далее, 21 гифка или картинка,

// ---------------------------------------------------------------

timerMinim ntpSyncTimer(1000 * 60 * SYNC_TIME_PERIOD); // Сверяем время с NTP-сервером через SYNC_TIME_PERIOD минут
timerMinim effectTimer(D_EFFECT_SPEED);  // Таймер скорости эффекта (шага выполнения эффекта)
timerMinim clockTimer(D_EFFECT_SPEED);   // Таймер смещения оверлея часов
timerMinim changeTimer(70);              // Таймер шага плавной смены режима - Fade
timerMinim halfsecTimer(500);            // Полусекундный таймер точек часов
timerMinim idleTimer(idleTime);          // Таймер бездействия ручного управлениядля автоперехода а демо-режим 
timerMinim dawnTimer(1000);              // Таймер шага рассвета для будильника "рассвет" 
timerMinim alarmSoundTimer(4294967295);  // Таймер выключения звука будильника
timerMinim fadeSoundTimer(4294967295);   // Таймер плавного включения / выключения звука
timerMinim saveSettingsTimer(15000);     // Таймер отложенного сохранения настроек

// ********************* ДЛЯ ПАРСЕРА КОМАНДНЫХ ПАКЕТОВ *************************

#define    UDP_PACKET_MAX_SIZE  1024     // максимальный размер выделяемого буфера для коммуникации по UDP каналу
#define    PARSE_AMOUNT 14               // максимальное количество значений в массиве, который хотим получить
#define    header '$'                    // стартовый символ управляющей посылки
#define    divider ' '                   // разделительный символ
#define    ending ';'                    // завершающий символ
 
int16_t    intData[PARSE_AMOUNT];        // массив численных значений после парсинга - для WiFi часы время синхр м.б отрицательным + 
                                         // период синхронизации м.б больше 255 мин - нужен тип int16_t
char       incomeBuffer[UDP_PACKET_MAX_SIZE]; // Буфер для приема строки команды из wifi udp сокета
char       replyBuffer[8];               // ответ клиенту - подтверждения получения команды: "ack;/r/n/0"

byte       ackCounter = 0;               // счетчик отправляемых ответов для создания уникальности номера ответа

// --------------- ВРЕМЕННЫЕ ПЕРЕМЕННЫЕ ПАРСЕРА ------------------

uint32_t   prevColor;
boolean    recievedFlag;
boolean    parseStarted;
byte       parse_index;
String     string_convert = "";
String     receiveText = "";
bool       haveIncomeData = false;
char       incomingByte;

int16_t    bufIdx = 0;                   // Могут приниматься пакеты > 255 байт - тип int16_t
int16_t    packetSize = 0;

enum       eModes {NORMAL, COLOR, TEXT} parseMode;


// ************************* УПРАВЛЕНИЕ МАТРИЦЕЙ *******************************

#define    NUM_LEDS            WIDTH * HEIGHT * SEGMENTS
#define    maxDim              max(WIDTH, HEIGHT)
#define    OVERLAY_SIZE        WIDTH * 11 * SEGMENTS

CRGB       leds[NUM_LEDS];                                   // обращение к светодиодам матрицы через этот массив
CRGB       overlayLEDs[OVERLAY_SIZE];                        // буфер оверлея; по максимуму - для бегущей строки во всю ширину матрицы или отображение календаря / вертикальных часов - 11 высота

// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

// ------------------- ВРЕМЕННЫЕ ПЕРЕМЕННЫЕ ----------------------

bool       saveSpecialMode = specialMode;
int8_t     saveSpecialModeId = specialModeId;
byte       saveMode;
byte       tmpSaveMode = 0;

// ---------------------------------------------------------------
