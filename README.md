# Christmas Lights
Christmas lights show using Arduino with Wizards of Winter of course!

# TODO
Complete readme

# Disclaimer
You need to work with your home AC outlet, this can be dangerous. Please get help if you don't have experience with this sort of things, better to be safe than sorry :smile:

## Information
This is a project for christmas lights manually synced(this is not a fun part) to (http://www.trans-siberian.com/)[Trans-Siberian Orchestra] Wizars of Winter. I used Arduino UNO to control 8 digital outputs. The outputs are connected to an [http://www.sainsmart.com/8-channel-dc-5v-relay-module-for-arduino-pic-arm-dsp-avr-msp430-ttl-logic.html](8 Relay Board).

## Development
I started building this using (http://www.vim.org/)[GVim] with (http://platformio.org/)[Platformio], later moved to (https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx)[Visual Studio 2015 Community Edition] with (http://www.visualmicro.com/)[Visual Micro] plugin, mainly to use integrated serial reader for debugging purposes.

## Circuit
This is my implementation
![Circuit](https://raw.githubusercontent.com/Beatusvir/christmas-lights/master/circuit.png)

### Platformio
Read the documentation in their webpage for details.
TL;DR
You create a folder for platformio files and to compilea and upload you need to go up a folder and execute `platformio run`, after the first 50 uploads I had to do thi:
Add this to vimrc
```
autocmd filetype arduino nnoremap <F5> :w <bar> exec '!cd .. && platformio run --target upload'<CR><CR>
```
