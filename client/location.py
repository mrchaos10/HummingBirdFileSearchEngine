import requests
import json

send_url = 'http://api.ipstack.com/14.139.161.13?access_key=8035aa5725135e492917fb310063f286&format=1'
r = requests.get(send_url)
data = json.loads(r.text)
IP=data['ip']
latitude=data['latitude']
longitude=data['longitude']
zips=data['zip']
types = data['type']
city = data['city']
region_name = data['region_name']
country_name = data['country_name']
continent_name = data['continent_name']

print 'Your details\n '
print'\n IP :'
print(IP)
print '\n Latitude :'
print(latitude)
print'\n Longitude :'
print(longitude)
print'\n ZIP :'
print(zips)
print'\n Types :'
print(types)
print'\n City :'
print(city)
print'\n Region Name :'
print(region_name)
print'\n Country Name :'
print(country_name)
print'\n Continent :'
print(continent_name)

