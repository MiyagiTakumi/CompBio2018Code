import discord
import asyncio
import random
from datetime import datetime, timedelta

client=discord.Client()

@client.event
async def on_ready():
    print('Logged in as')
    print(client.user.name)
    print(client.user.id)
    print('------')

    random.seed()

    t1 = datetime.today()
    t2 = datetime(year = 9999, month = 12, day = 31, hour = 22, minute = 20)

    td = t2 - t1

    print(str(td.total_seconds()%(60*60*24) - 60) + " sec till 22:19")
    await asyncio.sleep(td.total_seconds()%(60*60*24) - 60)
 
    while True:
        if datetime.today().hour == 22 and datetime.today().minute == 20:
            await client.send_message(client.get_channel("360524552666873868"), "★・乗船～っ！ヽ(`Д´)ﾉ")
            await asyncio.sleep(60*60*24 - 60)

        else:
            await asyncio.sleep(20)


@client.event
async def on_message(message):
    if message.content.startswith("★・") and message.author.bot == False:
        if datetime.today().hour != 22 and datetime.today().minute != 20:
            await client.send_message(message.channel, message.content)

    if message.content.startswith("!help"):
        await client.send_message(message.channel, "<@" + message.author.id + ">\n" +
                                 "Attention!\n\nYou have no permission to see the guide for this bot.\n" +
                                 "To get permission, send a picture of your penis, taken with some authentic scale(e.g. centimeter ruler), to @Surumeika_MM through DM.")

    if message.content.startswith("!albino"):
        n = random.randrange(365*100)
        if n%365 == 0:
            await client.send_message(message.channel, "★・アルビノ～っ！ヽ(`Д´)ﾉ")
            await client.send_message(message.channel, str(90 + n%110) + " cm")

        elif n%100 == 0:
            await client.send_message(message.channel, "★・ぬまち～っ！ヽ(`Д´)ﾉ")

        elif n < 365*40:
            await client.send_message(message.channel, "★・エチオピ～っ！ヽ(`Д´)ﾉ")
            await client.send_message(message.channel, str(90 + n%110) + " cm")

        else:
            await client.send_message(message.channel, "★・ドラド～っ！ヽ(`Д´)ﾉ")
            await client.send_message(message.channel, str(60 + n%60) + " cm")

    if message.content.startswith("!chinpo"):
        await client.send_message(message.channel, "(⋈◍＞◡＜◍)。✧♡　@Surumeika_MM")

    if message.content.startswith("!command"):
        await client.send_message(message.channel, "<@" + message.author.id +
                                 ">\n""Available command\n!albino\t!help\t!chinpo")





client.run('NDU5OTg1OTMwNjkwNzU2NjA5.Dg-K2g.hnATwH8aybj3yv4D1YyiQCRqHOU')