# Creating your own antenna for Wi-Fi and Bluetooth® <img align="right" width="100" height="100" src="/assets/logo.png">

<p align="left">
<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Googool/antenna?style=flat-square">
<img alt="GitHub all releases" src="https://img.shields.io/github/downloads/Googool/antenna/total?style=flat-square">
<img alt="GitHub" src="https://img.shields.io/github/license/Googool/antenna?style=flat-square">
</p>

Have you ever wondered how everyday devices, whether you use them or connect to them, such as Wi-Fi routers and Bluetooth® gadgets, communicate? 

With a quick search on [Google](https://letmegooglethat.com/?q=Does+WiFi+and+Bluetooth+both+use+2.4+GHz+band%3F), we learn that both Wi-Fi and Bluetooth® operate on the 2.4 GHz ISM band, spanning 83 MHz in width. What do these antennas, the 2.4 GHz antennas that facilitate our everyday use of these protocols, look like? And how can we make our own?

> If you're eager to dive into the practical aspects, [click here](#getting-started).

## Dissection

One of the first things we did was to investigate the internal structure of pre-made antennas by disassembling a few of them. This revealed that these antennas primarily consist of [monopole antennas](https://en.wikipedia.org/wiki/Monopole_antenna), - the half-siblings of [dipole antennas](https://en.wikipedia.org/wiki/Dipole_antenna).

If you do not wish to disassemble an antenna of your own, then you can [watch this video](https://www.youtube.com/watch?v=AHvZKYF-XS8) or refer to the picture below.

![dissassembled]()

## Radiation Pattern (Omnidirectional or Bidriectional)

We settled on the monopole antenna instead of the dipole antenna due to one of the characteristics of the monopole antenna, which is its [omnidirectional](https://en.wikipedia.org/wiki/Omnidirectional_antenna) (360°) nature. In contrast, the dipole antenna is [bidirectional](https://en.wikipedia.org/wiki/Dipole_antenna#Dipole_characteristics), which makes it impractical for use within moving devices, such as mobile phones, with Wi-Fi or Bluetooth®. However, you might find the dipole antenna useful when working with FM broadcasting, etc.

![comparison](https://github.com/Googool/antenna/blob/main/assets/comparison.png)

The reasoning behind why bidirectional is impractical in this case is that there will be dead spots where we are unable to reach. This means that if we move around, we might lose our signal, whereas with the omnidirectional signal, as illustrated above, we won't.

Using a bidirectional antenna can be compared to having a flashlight with a narrow beam; if you turn around, you'll find yourself in the dark. In contrast, an omnidirectional antenna is like a lantern that lights up the entire area, no matter which way you face.

Now that we know which type and pattern our antenna has to have, and we also know the frequency we want it for, we can move on to deciding the length of our open coaxial feed (or the length of our open wire).

## Coaxial Feed (Open Wire)

Knowing the desired operating frequency allows us to calculate the length of the open coaxial feed for our antenna.

To calculate the length of the open coaxial feed for our antenna, we will need to find the wavelength of our operating frequency. The formula to calculate the wavelength (λ) is: `λ = c / f`, where `c` is the speed of light (299,792,458 meters per second), and `f` is the desired frequency. 

So the calculation would look like this: `λ = 299,792,458 / 2,400,000`, which equals `125 millimeters`.

The length of the antenna is chosen to be a quarter-wavelength (λ/4) at the desired frequency to achieve impedance matching, as we are using a monopole antenna. To determine the length of our open coaxial feed, we need to divide the wavelength of the operating frequency by four, which is `125 / 4`, resulting in a length of `31 millimeters`.

Knowing the frequency allowed us to *approximate* the length of our open coaxial feed. To determine the exact length, we initially used our calculated length while having the coaxial cable connected to an impedance analyzer (the one we had lying around was the [N1201SA](https://www.banggood.com/da/AAI-ORIGINAL-English-Verison-N1201SA-N1201SA+-34_375MHz-2_7GHz-UV-RF-Vector-Impedance-ANT-SWR-Antenna-Analyzer-Meter-Tester-p-1988938.html?gmcCountry=DK&currency=DKK&cur_warehouse=CN&createTmp=1&utm_source=googleshopping&utm_medium=cpc_pt&utm_content=meruem&utm_campaign=aceng-pmax-dk-sucai-220714-meruem&ad_id=&gclid=CjwKCAjw9-6oBhBaEiwAHv1QvA5hgEXreKKL3_rbdD7rkZjbQio_vvt_4KRiKofrdsfhKSRjv36c1hoCkqQQAvD_BwE), which we purchased from Banggood), gradually stripping away a few millimeters at a time. Through practical tuning using the impedance analyzer, we ultimately chose an open coaxial feed length of `25 millimeters`, which is six millimeters less than the calculated length.

*Disclaimer: Explain that it might be different and always measure for yourself*

## Radiating Elements (Blades) - *Optional*

Choosing the length of our radiating elements (blades) was a bit tricky.

## Getting started

### What you need
