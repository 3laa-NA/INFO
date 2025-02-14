import { useState } from 'react'
import './App.css'
import Card from './Card'

function CardList(props) {
    const [cards, setCards] = useState(props.cardList)

    return (
        <div className="card-list">
            {cards.map((item, index) => (
                <Card 
                    key={index}
                    symbol={item.symbol}
                    affichage={item.affichage}
                />
            ))}
        </div>
    )
}

export default CardList