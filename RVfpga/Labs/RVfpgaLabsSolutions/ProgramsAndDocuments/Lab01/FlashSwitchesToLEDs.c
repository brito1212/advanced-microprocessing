
#define GPIO_SWs    0x80001400
#define GPIO_LEDs   0x80001404
#define GPIO_INOUT  0x80001408

#define DELAY 0x500000               /* Define o DELAY */

#define READ_GPIO(dir) (*(volatile unsigned *)dir)
#define WRITE_GPIO(dir, value) { (*(volatile unsigned *)dir) = (value); }

int main ( void )
{
  int En_Value=0xFFFF, switches_value, i, cnt;

  WRITE_GPIO(GPIO_INOUT, En_Value);

  while (1) { 
    switches_value = READ_GPIO(GPIO_SWs);
    switches_value = switches_value >> 16;  
    WRITE_GPIO(GPIO_LEDs, switches_value);
	
    // delay
    cnt = DELAY;
    i = 0;
    while (i < cnt)
        i++;
    
      WRITE_GPIO(GPIO_LEDs, 0);               // turn off LEDs 

    // delay
    i = 0;
    while (i < cnt)
        i++;
  }

  return(0);
}
