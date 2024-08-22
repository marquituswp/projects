import propTypes from 'prop-types';

function List(props){

    const itemList = props.items;
    const category = props.category;


    itemList.sort((a, b) => a.name.localeCompare(b.name)); // Alphabetical order
    // fruits.sort((a, b) => b.name.localeCompare(a.name)); // Reverse alphabetical order
    // fruits.sort((a, b) => a.calories - b.calories); // Ascending order
    // fruits.sort((a, b) => b.calories - a.calories); // Descending order

    // FILTERS
    // const lowCalfruit = fruits.filter((fruit) => fruit.calories < 100);
    // const highCalfruit = fruits.filter((fruit) => fruit.calories >= 100);

    const listItems= itemList.map((fruit) => <li key={itemList.id}>
                                                {fruit.name}: &nbsp;
                                                <b>{fruit.calories}</b>
                                            </li>);

    return (
        <>
        <h3 className="list-category">
            {category}
        </h3>
        <ol className="list-items">
            {listItems}
        </ol>
        </>
        
    );
}
List.propTypes = {
    category: propTypes.string,
    items: propTypes.arrayOf(propTypes.shape({  id: propTypes.number, 
                                                name: propTypes.string, 
                                                calories: propTypes.number})),
}
List.defaultProps = {
    category: 'Category',
    items: [],
}
export default List;