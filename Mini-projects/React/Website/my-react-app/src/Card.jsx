import profilePicture from './assets/FotoCara1.jpg';

function Card(){
    return(
        <div className="card">
            <img src={profilePicture} alt="Marcos López"/>
            <h2>Marcos López</h2>
            <p>I am studying software Engineering</p>
        </div>
    );
}

export default Card;