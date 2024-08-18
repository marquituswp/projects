import profilePicture from './assets/FotoCara1.jpg';

function Card(){
    return(
        <div className="card">
            <img src={profilePicture} alt="Marcos López" className='card-image'/>
            <h2 className='card-title'>Marcos López</h2>
            <p className='card-text'> I am studying software Engineering</p>
        </div>
    );
}

export default Card;