require 'sinatra'

class App < Sinatra::Base
  get '/' do
    'Goodbye, world!'
  end
end
