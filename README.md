# Christmas Lights
Christmas lights show using Arduino with Wizards of Winter of course!

# Disclaimer
You need to work with your home AC outlet, this can be dangerous. Please get help if you don't have experience with this sort of things, better to be safe than sorry :smile:

## Information
This is a project for christmas lights manually synced(this is not a fun part) to [Trans-Siberian Orchestra](http://www.trans-siberian.com/) Wizars of Winter. I used [Arduino](https://www.arduino.cc/) UNO to control 8 digital outputs. The outputs are connected to an [8 Relay Board](http://www.sainsmart.com/8-channel-dc-5v-relay-module-for-arduino-pic-arm-dsp-avr-msp430-ttl-logic.html). The relay board is powered with a separate power adapter because the arduino digital output is not enough for the 8 relays.

The audio source is my [Marantz NR1403](http://www.us.marantz.com/us/Products/Pages/ProductDetails.aspx?CatId=avreceivers&ProductId=NR1403) connected to [Boston Acoustics A25](http://www.bostonacoustics.com/US/Pages/Home.aspx), from the same cable that connects into the speaker, I connected another cable to the breadbord as seen in the ciruit below. 

## Development
I started building this using [GVim](http://www.vim.org/) with [Platformio](http://platformio.org/), later moved to [Visual Studio 2015 Community Edition](https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx) with [Visual Micro](http://www.visualmicro.com/) plugin, mainly to use integrated serial reader for debugging purposes.

## Circuit
In my opinion this was the hardest part, having analog input into arduino means you need to protect it against harmful signals (anything negative and above 5 v), because my source outputs a lot more than that I had to use and zener diode regulator.

Following the steps of Thomas Edison:
>I have not failed. I've just found 10,000 ways that won't work.

I succesfully found 3 ways to burn Arduino pings, then came this (using the wrong circuit for my source):
![Circuit](https://raw.githubusercontent.com/Beatusvir/christmas-lights/master/circuit.png)

### Parts
* 100k ohm resistor (from positive speaker terminal to rectifier)
* 1N4007 rectifier diode (from resistor to zener diode and analog input), to prevent negative voltage
* 4.7v zener (from analog input to ground), to clip voltage

### Platformio
Read the documentation in their webpage for details.

TL;DR
You create a folder for platformio files and to compile and upload you need to go up a folder and execute `platformio run --target upload`, after the first 50 times typing this...:

I added to vimrc
```
autocmd filetype arduino nnoremap <F5> :w <bar> exec '!cd .. && platformio run --target upload'<CR><CR>
```


# TODO
* Outlet connection
* It's too late, I may need to organize this doc