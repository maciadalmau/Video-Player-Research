# Video Player Research

Hi, I'm Macià Dalmau and welcome to my Video Player. This project has been made through a library called theora to play encoded videos as SDL textures. Also, this work is for a personal research assignment of the subject Project 2 in the Video Game design and development Degree in CITM, UPC.

## What's a Video Player?

Basically a video player is an application that reads, processes and plays the content of a video file. Video Players commonly display standard controls icons known such as play, pause, fastforward, backforward and stop buttons. In addition, they generally have progress bars to locate the current position in the duration of the video file. Examples of known Video Players would be Windows Media Player, QuickTime or VLC.  

<img src="https://user-images.githubusercontent.com/47743853/80913251-8ca26680-8d43-11ea-8c08-d7288284413c.jpg"  height="200"></img>


## Video Player in video games

In video games, the Video Player don't need so many functionalities. They usually have the options of play, pause and skip the video. But why is important on video games? Mainly for two very important reasons:

The importance of cinematics in video games gives the audience an idea of what a video game will be and gives animators the opportunity to attract potential customers. The cinema and animated scenes in the game offer even more creativity and content in an already exciting form of entertainment. The use of short movies in games, regardless of the type of game, increases the value and provides a method of engaging the player even more than before. Also, cinematics are a cool way to introduce the game or tell the story.

Sometimes, the scene you want to make in your video game is too complex to be processed in real time or basically you just don't want your team of developers to spend time creating a cinematic. Then you will need a pre-rendered scene and you will need a video player to process this pre-rendered scene in your game.

<img src="https://user-images.githubusercontent.com/47743853/80913284-d25f2f00-8d43-11ea-9ec9-821dae4aafa2.gif"  height="300"></img>


## Pre-rendered cutscenes vs Real time cutscenes

In video games cutscenes can be classified in many ways, but when talking about video rendering, there are two different categories: pre-rendered and real time cutscenes. Pre-rendered cutscenes, as the name implies, are cutscenes that have been rendered before, and the game just plays the cutscene with his video player. On the other hand we have real time cutscenes use the game engine to generate a cutscene that is rendered while the game is playing.

- Examples of Pre-rendered cutscenes:

<img src="https://user-images.githubusercontent.com/47743853/80912589-43034d00-8d3e-11ea-906c-7b597fd0bd63.gif"  height="300"></img>

<img src="https://user-images.githubusercontent.com/47743853/80912606-6c23dd80-8d3e-11ea-8232-d5d169e9d9a1.gif"  height="300"></img>

- Examples of Real time cutscenes:

<img src="https://user-images.githubusercontent.com/47743853/80912635-99708b80-8d3e-11ea-9c71-8dc313398093.gif"  height="300"></img>

<img src="https://user-images.githubusercontent.com/47743853/80912643-ab522e80-8d3e-11ea-876b-3893c20fef2b.gif"  height="300"></img>

## Video file

Before we start looking for the implementation I want to say something short about what a video file is.

A video file has three main parts:

<img src="https://user-images.githubusercontent.com/47743853/80734082-eb32cf00-8b0e-11ea-92e3-583afb8f4faa.png"  height="400"></img>


The container format is just a way of packing the audio and video data in a single file, togheter whit some additional information.

## Codec

A codec is a device or program which encodes or decodes a digital data stream. A coder encodes a data stream, signal transmission, or storage, possibly in encrypted form, and the decoder function reverses the encoding for playback or editing. Codecs are specially used in videoconferencing, streaming media and video editing applications. We need to do this because video and music files are really big, which makes them hard to transfer and store.


## Codec ecosystem and alternatives

So if you want to play some video in your game you have some alternatives. First of all you have to make sure that the video is encoded correctly, that the library you choose works on the platform and plays nice with your memory, file, sound and streaming abstractions, and that the audio and video doesn't desynchronize. But this is technical stuff. If you want to implement a video player you will have to read, understand and memorize all these patents.

You have to pick one of the existing alternatives and do the best you can with it. These are the main options you have:

#### Option 1: Bink

Bink from RAD game tools is as close as you can get to a de facto standard in the games industry, being used in more than 5800 games on 14 different platforms.

The main drawback of Bink is the pricing. At $ 8500 per platform per game, which can be a problem for a small game targeting multiple platforms.

People who want to play a lot of video in CPU taxing situations can still choose to integrate Bink. For them, the price and effort will be worth it.

#### Option 2: Platform especific

Another approach to video playing is to not develop a platform-independent library but instead use the video playing capabilities inherent in each platform. For example, Windows has Windows Media Foundation, MacOS has QuickTime, etc.

The biggest advantage is that on low-end platforms, using the built-in platform libraries can give you access to special video decoding hardware. For example, many phones have built-in H.264 decoding hardware. This means you can play video nearly for free, something that otherwise would be very costly on a low-end CPU.

But going platform specific also has a lot of drawbacks. If you target many platforms you have your work cut out for you in integrating all their different video playing backends. It adds an additional chunk of work that you need to do whenever you want to add a new platform.

Furthermore, it may be tricky to support the same capabilities on all different platforms.

#### Option 3: H.264

H.264 is used in Blu-ray players, video cameras, on iTunes, YouTube, etc. If you want a codec with good tool support and high quality, H.264 is the best choice.

However, H.264 is covered by patents. Patents that need to be licensed if you want to use H.264 without risking a lawsuit.

The H.264 patents are managed by an entity known as MPEG LA. They have gathered all the patents that they believe pertain to H.264 in “patent pool” that you can license all at once, with a single agreement.

#### Option 4: VP8 (WebM)

VP8 is a “free” video codec owned by Google. It is covered by patents, but Google has granted free use of those patents and also provides a BSD licensed library libvpx for encoding and decoding video files. The format is also endorsed by the Free Software Foundation.

It is generally acknowledged that when it comes to quality, VP8 is not quite as good as H.264, though the differences are not enormous. So you are trading some visual quality for the convenience of a license free format.

## Code Structure

We will use a library called TheoraPlay to play encoded videos as SDL textures. TheoraPlay is a library to make decoding of Ogg Theora videos easier. Free to use and patent unencumbered
http://icculus.org/theoraplay/


<img src="https://user-images.githubusercontent.com/47743853/80931072-e5134b80-8db7-11ea-8c35-a654cc2dc23c.png"  height="300"></img>

### TODO 1 
Decode the format. To do that we use THEORAPLAY_Decoder and THEORAPLAY_startDecodeFile();

The first parameter is the path of the file you want to decode.
The second parameter is the number of frames.
The third parameters is the format to decode: THEORAPLAY_VIDFMT_IYUV

### TODO 2 
After that we need to create a video and audio buffer and fill them with THEORAPLAY_getAudio and THEORAPLAY_getVideo. 


### TODO 3
Play video frames when it's time. Each frame need to be rendered during a certain amount of time, the time is specified in video->playms. If the time elapsed is greater than this we go to the next frame.


### TODO 4
Just free everything the texture, video, audio and decoder. Use THEORAPLAY_freeVideo(), THEORAPLAY_freeAudio() and THEORAPLAY_stopDecode.


### TODO 5
The last thing to do is pass the path and the renderer to the Load() function and save it to my_video variable.



## Code Structure
