'''
1 Install Required Dependancies
python -m pip install --upgrade pip setuptools wheel

2 Install Required Libraries
pip install SpeechRecognition gTTS playsound numpy transformers torch

'''


# for speech-to-text
import speech_recognition as sr

# for text-to-speech
from gtts import gTTS
from playsound import playsound

# for language model
from transformers import pipeline
import os
import time
import shutil

# for data
import datetime
import numpy as np

# Building the AI
class ChatBot:
    def __init__(self, channel):
        print(f"----- Starting up {channel} -----")
        self.channel = channel

    def speech_to_text(self, only_text=False):
        if only_text:
            print("Me  --> ", end="")
            self.text = input()
            return
        recognizer = sr.Recognizer()
        with sr.Microphone() as mic:
            recognizer.adjust_for_ambient_noise(mic)
            print("Listening...")
            audio = recognizer.listen(mic)
            self.text = "ERROR"
        try:
            self.text = recognizer.recognize_google(audio)
            print("Me  --> ", self.text)
        except:
            print("Me  -->  ERROR")



    def text_to_speech(self, text, only_text=False):
        print(f"{self.channel} --> {text}")

        if only_text:
            return

        temp_file = "temp.mp3"  # Use a simple filename
        speaker = gTTS(text=text, lang="en", slow=False)
        speaker.save(temp_file)

        new_path = os.path.abspath(temp_file)
        shutil.move(temp_file, new_path)  # Ensure no space issues

        try:
            playsound(new_path)
        except Exception as e:
            print("Error playing sound:", e)

        os.remove(new_path)




    def wake_up(self, text):
        return True if self.channel.lower() in text.lower() else False

    @staticmethod
    def action_time():
        return datetime.datetime.now().time().strftime("%H:%M")


# Running the AI
if __name__ == "__main__":
    channel = "Dev"
    ai = ChatBot(channel=channel)
    
    # Initialize the chatbot model (text generation instead of conversation)
    nlp = pipeline("text-generation", model="microsoft/DialoGPT-medium")

    os.environ["TOKENIZERS_PARALLELISM"] = "true"
    ex = True

    while ex:
        ai.speech_to_text(only_text=True)

        ## wake up
        if ai.wake_up(ai.text):
            res = "Hello, I am Dave the AI. What can I do for you?"
        ## action time
        elif "time" in ai.text:
            res = ai.action_time()
        ## respond politely
        elif any(i in ai.text for i in ["thank", "thanks"]):
            res = np.random.choice(
                [
                    "You're welcome!",
                    "Anytime!",
                    "No problem!",
                    "Cool!",
                    "I'm here if you need me!",
                    "Mention not",
                ]
            )
        elif any(i in ai.text for i in ["exit", "close", "bye"]):
            res = np.random.choice(
                [
                    "Tata",
                    "Have a good day",
                    "Bye",
                    "Goodbye",
                    "Hope to meet soon",
                    "Peace out!",
                ]
            )
            ex = False
        ## conversation
        else:
            if ai.text == "ERROR":
                res = "Sorry, come again?"
            else:
                # Generate response using DialoGPT
                response = nlp(ai.text, max_length=100, pad_token_id=50256, truncation=True)
                res = response[0]["generated_text"].strip()

        try:
            ai.text_to_speech(res, only_text=False)
        except:
            pass

    print(f"----- Closing down {channel} -----")
