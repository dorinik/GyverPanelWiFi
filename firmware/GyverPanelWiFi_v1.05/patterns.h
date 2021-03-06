#define MAX_PATTERN 14

CHSV colorMR[] = {
  CHSV(0,0,0),              // 0 - Black
  CHSV(HUE_RED,255,255),    // 1 - Red  
  CHSV(HUE_GREEN,255,255),  // 2 - Green
  CHSV(HUE_BLUE,255,255),   // 3 - Blue
  CHSV(HUE_YELLOW,255,255), // 4 - Yellow 
  CHSV(0,0,255),            // 5 - White
  CHSV(0,0,0),              // 6 - 1-й случайный цвет    
  CHSV(0,0,0),              // 7 - 2-й случайный цвет    
};

typedef uint8_t Pattern[10][10];

const Pattern patterns[] PROGMEM = {
{// 0 зигзаг ********
{6,6,6,6,6,7,7,7,7,7},  
{7,6,6,6,6,6,7,7,7,7},
{7,7,6,6,6,6,6,7,7,7},
{7,7,7,6,6,6,6,6,7,7},
{7,7,7,7,6,6,6,6,6,7},
{7,7,7,7,7,6,6,6,6,6},
{7,7,7,7,6,6,6,6,6,7},
{7,7,7,6,6,6,6,6,7,7},
{7,7,6,6,6,6,6,7,7,7},
{7,6,6,6,6,6,7,7,7,7}, 
},
{// 1 ноты ********* белые на цветном фоне
{6,6,6,6,6,5,5,5,6,6},
{6,6,6,6,6,5,6,6,5,6},
{6,6,6,6,6,5,6,6,6,6},
{6,6,6,6,6,5,6,6,6,6},
{6,6,6,6,6,5,6,6,6,6},
{6,6,5,5,5,5,6,6,6,6},
{6,5,5,5,5,5,6,6,6,6},
{6,6,5,5,5,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,5,6,6,6,6},
},
{// 2 ромб *********
{6,6,6,6,7,7,7,6,6,6},
{6,6,6,7,7,7,7,7,6,6},
{6,6,7,7,7,7,7,7,7,6},
{6,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
{6,7,7,7,7,7,7,7,7,7},
{6,6,7,7,7,7,7,7,7,6},
{6,6,6,7,7,7,7,7,6,6},
{6,6,6,6,7,7,7,6,6,6}, 
{6,6,6,6,6,7,6,6,6,6},
},
{// 3 сердце *********
{6,6,6,6,6,6,6,6,6,6},
{6,6,1,1,6,6,6,1,1,6},
{6,1,1,1,1,6,1,1,1,1},
{6,1,1,1,1,1,1,1,1,1},
{6,1,1,1,1,1,1,1,1,1},
{6,6,1,1,1,1,1,1,1,6},
{6,6,1,1,1,1,1,1,1,6},
{6,6,6,1,1,1,1,1,6,6},
{6,6,6,6,1,1,1,6,6,6}, 
{6,6,6,6,6,1,6,6,6,6},
},
{// 4 елка *********    зеленая на черном
{0,0,0,0,2,0,0,0,0,0},
{0,0,0,2,2,2,0,0,0,0},
{0,0,2,2,2,2,2,0,0,0},
{0,2,2,2,2,2,2,2,0,0},
{2,2,2,2,2,2,2,2,2,0},
{0,0,0,0,2,0,0,0,0,0},
{0,0,0,2,2,2,0,0,0,0},
{0,0,2,2,2,2,2,0,0,0},
{0,2,2,2,2,2,2,2,0,0},
{2,2,2,2,2,2,2,2,2,0}, 
},
{// 5 клеточка *********
{6,6,6,7,7,7,7,7,7,6},
{6,6,6,6,7,7,7,7,6,6},
{6,6,6,6,6,7,7,6,6,6},
{7,7,6,6,6,6,6,6,6,6},
{7,7,7,6,6,6,6,6,6,7},
{7,7,7,7,6,6,6,6,7,7},
{7,7,7,6,6,6,6,6,6,7},
{7,7,6,6,6,6,6,6,6,6},
{6,6,6,6,6,7,7,6,6,6},
{6,6,6,6,7,7,7,7,6,6}, 
},
{// 6 смайлик********* желтый на зеленом
{2,2,2,2,2,2,2,2,2,2},
{2,2,4,4,4,4,4,2,2,2},
{2,4,4,0,4,0,4,4,2,2},
{2,4,4,4,4,4,4,4,2,2},
{2,4,4,4,4,4,4,4,2,2},
{2,4,0,4,4,4,0,4,2,2},
{2,4,4,0,0,0,4,4,2,2},
{2,2,4,4,4,4,4,2,2,2},
{2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2}, 
},
{// 7 ********** зигзаг
{6,0,7,7,7,7,7,0,6,6},
{6,6,0,7,7,7,0,6,6,6},
{6,6,6,0,7,0,6,6,6,6},
{6,6,6,6,0,6,6,6,6,0},
{0,6,6,6,6,6,6,6,0,7},
{7,0,6,6,6,6,6,0,7,7},
{7,7,0,6,6,6,0,7,7,7},
{7,7,7,0,6,0,7,7,7,7},
{7,7,7,7,0,7,7,7,7,0},
{0,7,7,7,7,7,7,7,0,6},
},
{// 8 ********* полосы
{6,6,6,6,6,6,7,7,7,7},
{7,6,6,6,6,6,6,7,7,7},
{7,7,6,6,6,6,6,6,7,7},
{7,7,7,6,6,6,6,6,6,7},
{7,7,7,7,6,6,6,6,6,6},
{6,7,7,7,7,6,6,6,6,6},
{6,6,7,7,7,7,6,6,6,6},
{6,6,6,7,7,7,7,6,6,6},
{6,6,6,6,7,7,7,7,6,6},
{6,6,6,6,6,7,7,7,7,6},
},
{// 9 ********** волны
{6,7,7,7,6,6,7,7,7,6},
{6,6,7,6,6,6,6,7,6,6},
{6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
{7,6,6,6,7,7,6,6,6,7},
{7,7,6,7,7,7,7,6,7,7},
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
},
{// 10 ********* чешуя
{6,7,7,7,7,7,7,7,7,7},
{7,6,7,7,7,7,7,7,7,6},
{7,6,6,7,7,7,7,7,6,6},
{7,7,6,6,6,6,6,6,6,7},
{7,7,7,6,6,6,6,6,7,7},
{7,7,7,7,6,6,6,7,7,7},
{7,7,7,7,7,6,7,7,7,7},
{7,7,7,7,6,7,6,7,7,7},
{7,7,6,6,7,7,7,6,6,6},
{6,6,7,7,7,7,7,7,7,6},
},
{// 11 ********* портьера
{7,6,6,6,6,6,6,6,6,6},
{7,6,6,6,6,6,6,6,6,6},
{7,7,6,6,6,6,6,6,6,7},
{7,7,7,7,6,6,6,7,7,7},
{6,7,7,7,7,7,7,7,7,7},
{6,7,7,7,7,7,7,7,7,7},
{6,6,7,7,7,7,7,7,7,6},
{6,6,6,6,7,7,7,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
},
{// 12 ********* плетёнка
{7,7,7,7,7,7,7,7,7,6},
{7,7,7,7,7,7,7,7,6,7},
{7,7,7,7,7,7,7,6,6,6},
{6,7,7,7,7,7,6,6,6,6},
{6,6,7,7,7,6,7,6,6,6},
{6,6,6,7,6,7,7,7,6,6},
{6,6,6,6,7,7,7,7,7,6},
{6,6,6,7,7,7,7,7,7,7},
{7,6,7,7,7,7,7,7,7,7},
{6,7,7,7,7,7,7,7,7,7},
},
{// 13-снежинка
{6,6,6,6,6,6,6,6,6,6},
{6,6,5,6,6,6,5,6,6,6},
{6,6,6,5,6,5,6,6,6,6},
{6,5,6,5,5,5,6,5,6,6},
{6,6,5,5,6,5,5,6,6,6},
{6,5,6,5,5,5,6,5,6,6},
{6,6,6,5,6,5,6,6,6,6},
{6,6,5,6,6,6,5,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
{6,6,6,6,6,6,6,6,6,6},
},
};
