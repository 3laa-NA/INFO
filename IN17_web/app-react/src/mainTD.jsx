import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import Test from './Test.jsx'
import CardList from './CardList.jsx'
import CreateCard from './CreateCard.jsx'

const cardsList = [
  { symbol: 'X', affichage: 'hidden' },
  { symbol: 'O', affichage: 'hidden' },
  { symbol: 'X', affichage: 'hidden' },
  { symbol: 'O', affichage: 'hidden' }
]

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <Test text="lmao"/>
    <CardList cardList={cardsList}/>
    <CreateCard onSubmit={(newCard) => console.log(newCard)} />
  </StrictMode>
)
