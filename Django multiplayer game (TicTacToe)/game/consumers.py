import json
from channels.generic.websocket import AsyncWebsocketConsumer, WebsocketConsumer
from asgiref.sync import async_to_sync

from channels.exceptions import StopConsumer


class GAMEBUILDER(WebsocketConsumer):

    def connect(self):
        print('conectted')
        self.room_name = self.scope['url_route']['kwargs']['room_code']
        self.room_group_name = f'chat_{self.room_name}'

        async_to_sync(self.channel_layer.group_add)(
            self.room_group_name,
            self.channel_name
        )

        self.accept()

    def disconnect(self, close_code):
        # Leave room group

        async_to_sync(self.channel_layer.group_discard)(
            self.room_group_name,
            self.channel_name
        )
        raise StopConsumer()


    # recieve data which send by socket.send(data)
    def receive(self, text_data):
        print('recieve() text data =', text_data)
        # 1 )recieve() text data = {"data":{"player":"v","index":0,"type":"running"}}
        # 2) recieve() text data = {"data":{"player":"s","index":0,"type":"running"}}

        run_game=  {'type': 'run_game','payload': text_data}

        async_to_sync(self.channel_layer.group_send)(
            self.room_group_name,
            # this will called the run game function
            run_game
        )

    # this func is called by the recieve fun
    def run_game(self, event):
        print('event=', event)
        # 1.1 event= {'type': 'run_game', 'payload': '{"data":{"player":"s","index":0,"type":"running"}}'}

        dataStr = event['payload']
       
        dataObj = json.loads(dataStr)
        # data = {"data":{"player":"s","index":0,"type":"running"}

        # text_data = '{payload : {"player":"s","index":0,"type":"running"}}'
        self.send(text_data=json.dumps({
            'payload': dataObj['data']
        }))
    

